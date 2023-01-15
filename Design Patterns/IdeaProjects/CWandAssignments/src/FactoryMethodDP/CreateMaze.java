package FactoryMethodDP;

public class CreateMaze {

    public void roomMaker(){
        Maze aMaze = new Maze();
        aMaze.CreateMaze();

        Room room = new Room();
        room.makeRoom(1);
        room.makeRoom(2);
        aMaze.addRoom();
        aMaze.addRoom();
    }
}
