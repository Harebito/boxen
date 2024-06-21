import java.time.LocalTime;
import java.time.format.DateTimeFormatter;

public class DigitalClock extends Clock {
    public enum TimeFormat {
        H12,
        H24
    }
    private final TimeFormat timeFormat;
    public DigitalClock(TimeFormat timeFormat, City city) {
        super(city);
        this.timeFormat = timeFormat;

    }
    @Override
    public String toString() {
        if (timeFormat == TimeFormat.H24) {
            return super.toString();
        } else {
            int hour = localTime.getHour();
            String postfix;
            if (hour >= 0 && hour < 12) {
                postfix = "AM";
                if (hour == 0) {
                    hour = 12;
                }
            } else {
                postfix = "PM";
                if (hour != 12){
                    hour -= 12;
                }
            }
            return LocalTime.of(hour, localTime.getMinute(), localTime.getSecond())
                    .format(DateTimeFormatter.ofPattern("HH:mm:ss")) + " " + postfix;
        }
    }
}
