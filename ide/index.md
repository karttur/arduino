---
layout: page
title: Arduino IDE
excerpt: "An archive of posts on Arduinos Integrated Development Environment."
image: std-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
search_omit: true
---

Arduino comes with its own Integrated Development Environment (IDE). There is also a a tiny open source Python dialect that runs on microcontroller - MicroPython, and its sibling CircuitPython. CircuitPython is developed and maintained by Adafruit. Trying out CircuitPython in October 2022 I was quite happy with writing code that I understood, but CircuitPython lacks some parts that are required for running [xSpecte's spectrometer Printed Circuit Board](../spectrolum/spectrolum-v078-summary/) and I thus gave up on using CircuitPython. If the required functions are added then I will make another try. The processing stranded on the function _AnalogOut_ that is not available for nrF based microcontrollers in CircuitPython.

<ul class="post-list">
{% for post in site.categories.ide %}
  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
{% endfor %}
</ul>
