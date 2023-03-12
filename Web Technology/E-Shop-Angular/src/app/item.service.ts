import { Injectable } from '@angular/core';
import { Item } from './item';
// import { Item } from './item';
@Injectable({
  providedIn: 'root'
})
export class ItemService {

  constructor() { }

  items: Item[] = [
    {id: 1, name: "iPhone", price:2000, quantity: 3},
    {id: 2, name: "mcbook", price:10000, quantity: 2},
    {id: 3, name: "oppo", price:300, quantity: 8}
  ]

  getItems(): Item[]{
    return this.items;
  }
};

