Кагато описваме една страница, описваме нещата в блокове. Всеки блок си има стилови подразбирания.
По подразбиране заемат целия ред.
Има други типове секции като спам, те могат да имат
Всеки браузър си има входни данни по подразбиране.

```
<html>
    <head>
        <link href="style.css" rel="stylesheet">
    </head>
    <body>
        <div id="content">
            <header>
                <a href="">Login</a>
                <a href="">Sign up</a>
            </header>
            <nav>
                Computer Graphics with WebGL
            </nav>
            <div>
                <h1>Computer Graphics with WebGL</h1>    
            </div>
        </div>
    </body>
</html>

// style.css

/* http://meyerweb.com/eric/tools/css/reset/
   v2.0 | 20110126
   License: none (public domain)
*/

html, body, div, span, applet, object, iframe,
h1, h2, h3, h4, h5, h6, p, blockquote, pre,
a, abbr, acronym, address, big, cite, code,
del, dfn, em, img, ins, kbd, q, s, samp,
small, strike, strong, sub, sup, tt, var,
b, u, i, center,
dl, dt, dd, ol, ul, li,
fieldset, form, label, legend,
table, caption, tbody, tfoot, thead, tr, th, td,
article, aside, canvas, details, embed,
figure, figcaption, footer, header, hgroup,
menu, nav, output, ruby, section, summary,
time, mark, audio, video {
	margin: 0;
	padding: 0;
	border: 0;
	font-size: 100%;
	font: inherit;
	vertical-align: baseline;
}
/* HTML5 display-role reset for older browsers */
article, aside, details, figcaption, figure,
footer, header, hgroup, menu, nav, section {
	display: block;
}
body {
	line-height: 1;
}
ol, ul {
	list-style: none;
}
blockquote, q {
	quotes: none;
}
blockquote:before, blockquote:after,
q:before, q:after {
	content: '';
	content: none;
}
table {
	border-collapse: collapse;
	border-spacing: 0;
}

#content {
    height: 960px;
    margin: 0 auto;
}

#content header {
    text-align: right;
}

#content nav {
    float: left;
    width:  30%;
}

#content nav a:hover {
    background: green;
}

#content > div {
    float: right;
    width: 70%;
}

#content > div h1 {
    border-bottom: 2px solid green;
}

```
