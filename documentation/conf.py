DOXYFILE = 'Doxyfile'

LINKS_NAVBAR1 = [
    ("<a href=\"/\">Courses</a>", [(None ,'md_intro_README'), (None, 'md_portfolio_README'), (None, 'md_artificialintelligence_README')]),
    # ("Namespaces", 'namespaces', [])
]

# Add your own navbar links using the code below.
# To find the valid link names, you can inspect the URL of a generated documentation site.

# LINKS_NAVBAR1 = [
#     (None, 'pages', [(None, 'about')]),
#     (None, 'namespaces', [(None, 'namespaceconcurrency')]),
# ]
#
# LINKS_NAVBAR2 = [
#     (None, 'annotated', [(None, 'classconcurrency_1_1_concurrency')]),
#     (None, 'files', [(None, 'concurrency_8h')]),
# ]

FINE_PRINT = """Awesome GameDev Resources. Created by <a href="https://linktree.com/tolstenko">Alexandre Tolstenko</a> and <a href="https://github.com/InfiniBrains/Awesome-GameDev-Resources/graphs/contributors">Others</a>. 2023. All rights reserved."""

HTML_HEADER = """<!-- Google tag (gtag.js) -->
<script async src="https://www.googletagmanager.com/gtag/js?id=G-76LZTVL113"></script>
<script>
  window.dataLayer = window.dataLayer || [];
  function gtag(){dataLayer.push(arguments);}
  gtag('js', new Date());

  gtag('config', 'G-76LZTVL113');
</script>
<script type='text/javascript'>
  window.smartlook||(function(d) {
    var o=smartlook=function(){ o.api.push(arguments)},h=d.getElementsByTagName('head')[0];
    var c=d.createElement('script');o.api=new Array();c.async=true;c.type='text/javascript';
    c.charset='utf-8';c.src='https://web-sdk.smartlook.com/recorder.js';h.appendChild(c);
    })(document);
    smartlook('init', '2f5d1221ea7a962d4adf10180eedd4eab3e00fc4', { region: 'eu' });
</script>
"""