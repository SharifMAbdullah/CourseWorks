import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';
import { Item } from '../item';
import { ItemService } from '../item.service';

@Component({
  selector: 'app-item-list',
  templateUrl: './item-list.component.html',
  styleUrls: ['./item-list.component.css']
})
export class ItemListComponent implements OnInit{
  constructor(private itemService: ItemService, private router: Router){}
  myItems: Item[] = [];
  ngOnInit(): void {
    this.myItems = this.itemService.getItems();
    console.log(this.myItems);
    //throw new Error('Method no implemented');
  }


  requestItem(): void{
    alert("Item request");
  }

  buy(ID:number):void{
    this.itemService.decrement(ID);
  }

  updateItem(index: number): void{
    this.itemService.setItemToBeUpdated(index);
    this.router.navigate(["update"]);
  }

}
