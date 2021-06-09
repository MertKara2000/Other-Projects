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

# We get the url2
f = open("url2.txt", "r")
r = requests.get(f.read())
soup = BeautifulSoup(r.content,"html.parser")

words = []
words = soup.get_text().split()


total2 = Counter((y.lower() for y in words ))
list_most_common_words2 = total2.most_common()

# We get the words within h1s
text_h1 = (''.join(s.findAll(text=True))for s in soup.findAll('h1'))
c_h1 = Counter((x.rstrip(punctuation).lower() for y in text_h1 for x in y.split()))

# We get the words within title
text_title = (''.join(s.findAll(text=True))for s in soup.findAll('title'))
c_title = Counter((x.rstrip(punctuation).lower() for y in text_title for x in y.split()))

# We decide keywords2 in here 
key_words2 = []
key_words2 = list(c_h1.keys())
key_words2.extend(c_title.keys())
key_words2 = set(key_words2)

if not key_words2:
    most_common_five2 = []
    most_common_five2.extend(list_most_common_words[:5])
    key_words2 = [a_tuple[0] for a_tuple in most_common_five2]

try:
    key_words2.remove('')
except:
    pass



for i in key_words:
    for j in list_most_common_words:
        if j[0] == i:
            print("<br>{}".format(j[1]))

print("<br>{}".format(key_words2))
        
for i in key_words2:
    for j in list_most_common_words2:
        if j[0] == i:
            print("<br>{}".format(j[1]))

similarity_score = 0
for i in key_words:
    for j in list_most_common_words2:
        if j[0] == i:
            similarity_score = similarity_score+j[1]
    
    for j in key_words2:
        if j == i:
            similarity_score = similarity_score+100
    
print("<br>Benzerlik skoru = {}".format(similarity_score))
    
