public class ReamHMexico extends AbstractLocale {
    public ReamHMexico () {
        super("Mexico", "Spanish");
    }
    
    public String getLocalTime(int hour, int min) {
        return String.format("%d:%02d", hour, min);
    }

    public String getGreeting() {
        return "Hola";
    }

    public String getCurrencySymbol() {
        return "$";
    }

    public double getCurrencyValue(double dollarAmount) {
        return dollarAmount * 19.38;
    }
}