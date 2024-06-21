import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public abstract class Clock {
    protected LocalTime localTime;
    private City city;

    public void setCity(City city) {
        float oldTimezone = this.city.getTimezone();
        float newTimezone = city.getTimezone();
        this.city = city;
        float diff = oldTimezone - newTimezone;
        this.localTime = this.localTime.minusMinutes((long)(60 * diff));
    }

    public Clock(City city) {
        this.city = city;
    }

    public void setCurrentTime() {
        localTime = LocalTime.now();
    }
    public void setTime(int hour, int minute, int second) {
        if (hour <= 24 && minute <= 59 && second <= 59 && hour >= 0 && minute >= 0 && second >= 0) {
            localTime = LocalTime.of(hour, minute, second);
        } else {
            throw new IllegalArgumentException("Invalid time value");
        }

    }
    public String toString() {
        return localTime.format(DateTimeFormatter.ofPattern("HH:mm:ss"));
    }


}
