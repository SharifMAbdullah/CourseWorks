package Observer;

import java.io.IOException;
import java.nio.file.*;
import java.util.ArrayList;
import java.util.Date;

public abstract class Subject {
    ArrayList<Observers> observersArrayList = new ArrayList<>();
    public abstract void registeredObserver(Observers observers);
    public abstract void unregisteredObserver(Observers observers);
    public abstract void notifyy(String fileName, String changeType, String changeTime);
}

class concreteSubject extends Subject{
    private String fileName;
    private String path;
    @Override
    public void registeredObserver(Observers observer) {
        observersArrayList.add(observer);
    }

    @Override
    public void unregisteredObserver(Observers observer) {
        observersArrayList.remove(observer);
    }

    @Override
    public void notifyy(String fileName, String changeType, String changeTime) {
        for (Observers itr: observersArrayList) {
            itr.update("a","b","c");
        }
    }
    public concreteSubject(String fileName, String path){
        this.fileName=fileName;
        this.path=path;
    }
    public void getUpdate() throws IOException, InterruptedException {
        WatchService watchService = FileSystems.getDefault().newWatchService();
        Path dirPath = Paths.get(path);
        System.out.println(dirPath);
        dirPath.register(watchService, StandardWatchEventKinds.ENTRY_MODIFY);

        while (true) {
            WatchKey key = watchService.take();

            for (WatchEvent<?> event : key.pollEvents()) {
                String eventFileName = event.context().toString();

                if (eventFileName.equals(fileName)) {
                    String changeType = event.kind().name();
                    String changeTime = new Date().toString();

                    notifyy(fileName, changeType, changeTime);
                }
            }
        }
    }
}