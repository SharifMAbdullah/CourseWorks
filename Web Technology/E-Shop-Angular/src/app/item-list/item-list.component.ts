import {Component, OnInit} from '@angular/core';
import { ItemService } from '../item.service';
import { Item } from '../item';

@Component({
  selector: 'app-item-list',
  templateUrl: './item-list.component.html',
  styleUrls: ['./item-list.component.css']
})

export class ItemListComponent implements OnInit{
  
    constructor(private ItemService: ItemService) {};
    myItems: Item[] = [];
    ngOnInit():void{
      console.log(this.ItemService.getItems());
      this.myItems = this.ItemService.getItems();
  }
}
