import requests
import json

# Estuve utilizando 'https://rickandmortyapi.com/'

url = 'https://rickandmortyapi.com/api/character/631'
r = requests.get(url).text
print(r)
print("\n-----------------------------\n")

r = requests.get(url)
j = r.json()
status = j['name']
print (status)
print("\n-----------------------------\n")


i = 1
while i<11:
    url = 'https://rickandmortyapi.com/api/character/{}'.format(i)
    r = requests.get(url)
    j = r.json()
    name = j['name']
    status = j['status']
    print (f'El personaje es {name} y su estado es {status}')
    i+=1

# haciendo una consulta un poquito más compleja:    
url = 'https://rickandmortyapi.com/api/episode/1'
r = requests.get(url)
j = r.json()
characters = j['characters']
characters_list = list()

for char in characters:
    r = requests.get(char)
    j2 = r.json()
    name = j2['name']
    characters_list.append(name)
    
for ch in characters_list:
    print(ch)
    
    
    
