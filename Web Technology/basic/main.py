from fastapi import FastAPI
from model import Item
app = FastAPI()

@app.get('/')
async def read_root():
    return {'message': 'poca sharif World'}

@app.get('/(id)')
async def read_root(id: int):
    return {'message': '1234'}

@app.get('/int/{id}', response_model = int)
async def read_root(id: int):
    return id

@app.get('/hu/{yes}', response_model = bool)
async def ggg(yes: bool):
    return yes

@app.post("/item/", response_model = Item)
async def post_item(item:Item):
    return item

@app.put("/item/", response_model = Item)
async def post_item(item:Item):
    return item

@app.delete("/item/", response_model = Item)
async def post_item(item:Item):
    return item