# browser

Each tab has a URL (character string) and data and time when loading the page (integer). The URL is that of the currently loaded page in the tab. When a page loads in a tab, it is automatically remembered as a unix timestamp with time and access data.
At this time, the browser user can only work with one of all the tabs that will call current. From the current tab we can transfer to any of its immediate neighbors - either before it or after it. Of course, this only happens if there are any (for example, the first tab has no other before it). For this purpose, reverse (forward) or forward (forward) direction operations are supported the current tab.
We assume that there is always at least one tab open in the browser. 
- If the user closes the last tab, a new one opens, loading the address "about: blank".
- When the browser is started, before the user can enter commands, in this case a tab is created, again with the address "about: blank". In both cases, this tab becomes current.
- If the user opens a new tab, he must add it immediately after the current one and in your queue to become current.
- If he closes a tab, it is currently the one immediately after it, and if there is no tab, it is the one before it. If this was the last tab, the rule described above in the text applies.
 
 **A program is implemented interface in which the following commands can be entered:**

| COMMANDS  | DESCRIPTION |
| ------------- | ------------- |
| GO <url>  | Creates tab with URL <url> in the current tab.|
| INSERT <url>  | Adds a new tab. Automatically updates the timestamp. The new one becomes the current one. |
| BACK | Goes to the previous tab. If there is no such, nothing happens.|
| FORWARD | Goes to the next tab. If there is no such, nothing happens.|
| REMOVE | Removes the previous tab. The next tab becomes the current one. If the current tab is the last one, new one is opened with address "about:blank".|
| PRINT | Prints all tabs. Between two tab there is ">"|



 

