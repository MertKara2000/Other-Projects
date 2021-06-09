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

print(list_most_common_words)

