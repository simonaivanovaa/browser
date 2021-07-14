# browser
Each tab has a URL (character string) and data and time when loading the page (integer). The URL is that of the currently loaded page in the tab. When a page loads in a tab, it is automatically remembered as a unix timestamp with time and access data.
At this time, the browser user can only work with one of all the tabs that will call current. From the current tab we can transfer to any of its immediate neighbors - either before it or after it. Of course, this only happens if there are any (for example, the first tab has no other before it). For this purpose, reverse (forward) or forward (forward) direction operations are supported the current tab.
We assume that there is always at least one tab open in the browser. If the user closes the last tab, a new one opens, loading the address "about: blank".
When the browser is started, before the user can enter commands, in this case a tab is created, again with the address "about: blank". In both cases, this tab becomes current.
If the user opens a new tab, he must add it immediately after the current one and in your queue to become current.
If he closes a tab, it is currently the one immediately after it, and if there is no tab, it is the one before it. If this was the last tab, the rule described above in the text applies.
