import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.Map;
import java.util.stream.Collectors;

public class City {
    private String name;
    private Float timezone;
    private Float longitude;

    public Float getLongitude() {
        return longitude;
    }

    public Float getTimezone() {
        return timezone;
    }

    @Override
    public String toString() {
        return "City{" +
                "name='" + name + '\'' +
                ", timezone=" + timezone +
                ", longitude=" + longitude +
                '}';
    }

    public String getName() {
        return name;
    }

    private static City parseLine(String line) {
        String[] parts = line.split(",");
        String name = parts[0];
        Float timezone = Float.parseFloat(parts[1]);

        String[] longitudeParts = parts[2].split(" ");
        Float longitude = Float.parseFloat(longitudeParts[0]);
        if (longitudeParts[1].equals("W")){
            longitude *= -1;
        }
        return new City(name, timezone, longitude);
    }
    public static Map<String,City> parseFile(String fileName) throws IOException {
        Map<String,City> cities = new HashMap<>();
        return Files.lines(Path.of(fileName))
                .skip(1)
                .map(City::parseLine)
                .collect(Collectors.toMap(City::getName,city->city));
    }
    private City(String name, Float timezone, Float longitude) {
        this.name = name;
        this.timezone = timezone;
        this.longitude = longitude;
    }
}
