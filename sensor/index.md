---
layout: page
title: Sensors
excerpt: "Archive on posts on sensors that can be used together with Arduino boards."
image: std-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
search_omit: true
---

This post lists a variety of sensors and probes that have been used or tested as part of different generations of the xSpectrolum spectrometer. The sensors are listed from the kind of properties they record:

- [Spectral sensors](#spectral-sensors)
- [Distance (proximity) sensors][#distance-(proximity)-sensors]
- [Ambient light sensors](#ambient-light-sensors)
- [Moisture sensors](#moisture-sensors)
- [Temperature sensors](#temperature-sensors)
- [Ambient gas sensors](#ambient-gas-sensors)

### Spectral sensors

<ul class="post-list">
{% for post in site.categories.sensor %}

  {% if post.sensingfeature %}

    {% if post.sensingfeature == "spectra" %}

  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
  {% endif %}
  {% endif %}
{% endfor %}
</ul>

### Distance (proximity) sensors

<ul class="post-list">
{% for post in site.categories.sensor %}

  {% if post.sensingfeature %}

    {% if post.sensingfeature contains "distance" or post.sensingfeature contains "proximity" %}

  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
  {% endif %}
  {% endif %}
{% endfor %}
</ul>

### Ambient light sensors

<ul class="post-list">
{% for post in site.categories.sensor %}

  {% if post.sensingfeature %}

    {% if post.sensingfeature contains "ambient-light" %}

  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
  {% endif %}
  {% endif %}
{% endfor %}
</ul>

### Moisture sensors

<ul class="post-list">
{% for post in site.categories.sensor %}

  {% if post.sensingfeature %}

    {% if post.sensingfeature contains "moisture" %}

  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
  {% endif %}
  {% endif %}
{% endfor %}
</ul>

### Temperature sensors

<ul class="post-list">
{% for post in site.categories.sensor %}

  {% if post.sensingfeature %}

    {% if post.sensingfeature contains "temperature" %}

  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
  {% endif %}
  {% endif %}
{% endfor %}
</ul>

### Ambient gas sensors

<ul class="post-list">
{% for post in site.categories.sensor %}

  {% if post.sensingfeature %}

    {% if post.sensingfeature contains "ambient-gas" %}

  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
  {% endif %}
  {% endif %}
{% endfor %}
</ul>

### All sensors

<ul class="post-list">
{% for post in site.categories.sensor %}
  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.title }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} <span class="excerpt">{{ post.excerpt | remove: '\[ ... \]' | remove: '\( ... \)' | markdownify | strip_html | strip_newlines | escape_once }}</span>{% endif %}</a></article></li>
{% endfor %}
</ul>
