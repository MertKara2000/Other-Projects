import requests
from bs4 import BeautifulSoup
from collections import Counter
from string import punctuation
import re
from urllib.request import Request, urlopen

f = open("url.txt", "r")
r = requests.get(f.read())
soup = BeautifulSoup(r.content,"html.parser")

words = []
words = soup.get_text().split()


total = Counter((y.lower() for y in words ))
list_most_common_words = total.most_common()

# We get the words within h1s
text_h1 = (''.join(s.findAll(text=True))for s in soup.findAll('h1'))
c_h1 = Counter((x.rstrip(punctuation).lower() for y in text_h1 for x in y.split()))

# We get the words within title
text_title = (''.join(s.findAll(text=True))for s in soup.findAll('title'))
c_title = Counter((x.rstrip(punctuation).lower() for y in text_title for x in y.split()))


# We decide keywords in here 
key_words = []
key_words = list(c_h1.keys())
key_words.extend(c_title.keys())
key_words = set(key_words)

try:
    key_words.remove('')
except:
    pass


if not key_words:
    most_common_five = []
    most_common_five.extend(list_most_common_words[:5])
    key_words = [a_tuple[0] for a_tuple in most_common_five]
    
    

print(key_words)