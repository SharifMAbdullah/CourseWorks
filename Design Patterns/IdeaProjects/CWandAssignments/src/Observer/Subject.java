package Observer;

import java.io.IOException;
import java.nio.file.*;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Calendar;
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
            itr.update(fileName,changeType,changeTime);
        }
    }
    public concreteSubject(String fileName, String path){
        this.fileName=fileName;
        this.path=path;
    }
    public void getUpdate() throws IOException, InterruptedException {
        String pathStr = ".";
        Path path= Paths.get(pathStr);
        System.out.println(path);
        try (final WatchService watchService = FileSystems.getDefault().newWatchService()) {
            final WatchKey watchKey = path.register(watchService, StandardWatchEventKinds.ENTRY_MODIFY);
            while (true) {
                final WatchKey wk = watchService.take();
                for (WatchEvent<?> event : wk.pollEvents()) {
                    final Path changed = (Path) event.context();
                    System.out.println(changed);
                    System.out.println(event.kind());
                    System.out.println(changed);
                    if (changed.endsWith("a")) {
                        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(Calendar.getInstance().getTime());
                        System.out.println("My file has changed at "+timeStamp);
                    }
                }
                // reset the key
                boolean valid = wk.reset();
                if (!valid) {
                    System.out.println("Key has been unregistered");
                }
            }
        } catch(Exception err){
            err.printStackTrace();
        }
    }
}