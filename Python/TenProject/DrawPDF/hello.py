from reportlab.graphics.shapes import Drawing, String
from reportlab.graphics import renderPDF
d = Drawing(100, 100)
s = String(30, 30, 'CHINA SCNU', textAnchor='middle')
d.add(s)
renderPDF.drawToFile(d, 'China.pdf', "A simple PDF file")
