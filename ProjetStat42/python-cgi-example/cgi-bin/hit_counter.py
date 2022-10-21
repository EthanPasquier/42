#! /usr/bin/env python3

import html
import cgitb
import time
import os
import requests
cgitb.enable()

hit_count_path = os.path.join(os.path.dirname(__file__), "hit-count.txt")

if os.path.isfile(hit_count_path):
    with open(hit_count_path) as fp:
        hit_count_str = fp.read()
        try:
            hit_count = int(hit_count_str)
        except ValueError:
            hit_count = 0
    hit_count += 1
else:
    hit_count = 1

with open(hit_count_path, 'w') as fp:
    fp.write(str(hit_count))

header = "Content-type: text/html\n\n"


date_string = time.strftime('%A, %B %d, %Y at %I:%M:%S %p %Z')

toto = 1000

html = """
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Stats42Quebec</title>
</head>
<body>
  <p>
  <h1 style="text-align: center;"><strong>Les xp de 42 quebec</strong></h1>
  <p>
</body>
</html>
""".format(html.escape(date_string), html.escape(str(hit_count)),html.escape(str(toto)))

print(header + html)
