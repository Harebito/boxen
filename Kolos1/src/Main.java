import org.w3c.dom.ls.LSOutput;

import java.io.IOException;
import java.util.Map;

public class Main {
    public static void main(String[] args) throws IOException {
//    Clock clock = new Clock();
//    clock.setCurrentTime();
//
//    System.out.println(clock);
//        Clock clock = new DigitalClock(DigitalClock.TimeFormat.H12);
//        clock.setTime(20,0,0);
//        System.out.println(clock);
        Map<String,City> cities = City.parseFile("/home/user/Downloads/strefy.csv");
        //cities.forEach((key,city) -> System.out.println(city));
        DigitalClock dClock = new DigitalClock(DigitalClock.TimeFormat.H12, cities.get("Kijów"));
        dClock.setCurrentTime();
        System.out.println("Kijów" + dClock);
        dClock.setCity(cities.get("Warszawa"));
        System.out.println("Warszawa" + dClock);
    }
}