"""Check that the WebAssembly game starts in a browser and reacts to clicks."""
import base64
import sys
import time

from playwright.sync_api import sync_playwright

URL = "http://localhost:8000/carnaval_tic_tac_toe.html"

with sync_playwright() as p:
    browser = p.chromium.launch(channel="chrome")
    # The same size as the iframe on the website
    page = browser.new_page(viewport={"width": 147, "height": 336})
    errors = []
    page.on("pageerror", lambda e: errors.append(str(e)))
    page.goto(URL)
    time.sleep(10)
    before = page.screenshot()
    for x in range(20, 147, 40):
        for y in range(20, 336, 40):
            page.mouse.click(x, y)
    time.sleep(1)
    after = page.screenshot()
    browser.close()

print("Screenshot:", base64.b64encode(after).decode())
if errors:
    sys.exit(f"Page errors: {errors}")
if before == after:
    sys.exit("Clicking did not change the page")
