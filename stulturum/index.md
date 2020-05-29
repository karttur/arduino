---
layout: page
title: Stulturum spectrometers
excerpt: "Archive of different versions of Stulturum's mobile phone spectrometer."
image: std-trmm-3b43v7-precip_3B43_trmm_2001-2016_A
search_omit: true
---

<ul class="post-list">
{% for post in site.categories.spectrolum %}
  <li><article><a href="{{ site.url }}{{ post.url }}">{{ post.version }} <span class="entry-date"><time datetime="{{ post.date | date_to_xmlschema }}">{{ post.date | date: "%B %d, %Y" }}</time></span>{% if post.excerpt %} {% endif %}</a></article></li>
{% endfor %}
</ul>
