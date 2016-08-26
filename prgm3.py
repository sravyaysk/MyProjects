import urllib
from BeautifulSoup import *

url = raw_input('Enter - ')
position=int(raw_input('Enter position-'))
count=int(raw_input('Enter count-'))
res=''
a=''
while(count>0):
	html = urllib.urlopen(url).read()
	soup = BeautifulSoup(html)
	tags = soup('a')

	index = 0
	for tag in tags:
		index += 1
		print index, " - ", tag.get('href', None)
		if index==position:
			url=tag.get('href', None)
			count=count-1
			if count==0:
				res=url
			break
	print res
	a=res.split('/')[-1]
	print a
	c=0
	k=0
	for i in range(0,len(a)):
		if(a[i]=='_'):
			c=c+1
			if c==2:
				k=i
				break
	print a[k+1:len(a)-5]