package Builder;

public class MazeBuilder {
    public void BuildMaze() { };
    public void BuildRoom(int room) { };
    public void BuildDoor(int roomFrom, int roomTo) { };
    Maze GetMaze() { return GetMaze().maze; }
    protected void MazeBuilder(){};
}
