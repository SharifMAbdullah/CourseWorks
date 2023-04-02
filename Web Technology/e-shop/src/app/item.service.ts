import { Injectable } from '@angular/core';
import { Item } from './item';

@Injectable({
  providedIn: 'root'
})
export class ItemService {

  constructor() { }


  items: Item[] = [
    {id: 1, name: "Iphone", price: 2000, quantity: 0},
    {id: 2, name: "mac-book", price: 10000, quantity: 30},
    {id: 3, name: "PC", price: 50000, quantity: 3}
  ];

  itemTobeUpdated: Item = new Item();
  getItems(): Item[]{
    return this.items;
  }

  decrement(ID: number):void{
    this.items[ID-1].quantity--;
  }

  setItemToBeUpdated(index: number): void{
    let item = this.items.at(index);
    if(item!=null){
      this.itemTobeUpdated = item;
    }
  }

  getItemToBeupdated():Item{
    return this.itemTobeUpdated;
  }


}
