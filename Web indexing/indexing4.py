import requests
from bs4 import BeautifulSoup
from collections import Counter
from string import punctuation
import re
from urllib.request import Request, urlopen

def getLinks(url):
    
    req = Request(url)
    html_page = urlopen(req)

    soup = BeautifulSoup(html_page, "html.parser")

    links = []
    for link in soup.findAll('a'):
        links.append(link.get('href'))
    return links

def GetSimilarityScore(url,url2):
    
    r = requests.get(url)
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
    
    print("<br>{}".format(key_words))    

    # We get the url2
    r = requests.get(url2)
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
    return similarity_score
    
    
    


f = open("url.txt", "r")
url = f.read()
# r = requests.get(f.read())
# soup = BeautifulSoup(r.content,"html.parser")


with open('url2.txt', "r") as word_list:
    urls = word_list.read().split(' ')

all_scores = []
    
for url2 in urls:
    links = getLinks(url2)
    links = set(links)

    str1 = 'http'
    str2 = '#'
    str3 = url2
    real_links = []
    for link in links:
        try:
            if link.find(str1) != -1 or  link.find(str2) != -1:
                if link.find(str3) != -1:
                    real_links.append(link)
            else :
                link = url2+link
                real_links.append(link)
        except:
            pass        

    i=0  
    all_links = []
    real_all_links = []
    for link in real_links:
        i=i+1
        try :
            all_links.extend(getLinks(link))
        except:
            pass

    i=0    
    for link in all_links:
        i=i+1
        try:
            if link.find(str1) != -1 or  link.find(str2) != -1:
                if link.find(str3) != -1:
                    real_all_links.append(link)
            else :
                link = url2+link
                real_all_links.append(link)
        except:
            pass        

    real_all_links.extend(real_links)
    real_links = set(real_links)
    real_all_links = set(real_all_links)
    
    
    p1 = GetSimilarityScore(url,url2)
    
    for level1url in real_links:
        p2 = 0
        p2 = p2+GetSimilarityScore(url,level1url)
        p2 = p2/len(real_links)
    
    for level2url in real_all_links:
        p3 = 0
        p3 = p3+GetSimilarityScore(url,level2url)
        p3 = p3/len(real_all_links)

    ult_score = p1+p2/3+p3/9
    print("<br>{}".format(ult_score))
    
    all_scores.append(ult_score)
    
print("<br>sırasıyla web sitelerinin benzerlik skorları")    
for score in all_scores:
    print("<br>{}".format(score))     
    
    
    
    
    