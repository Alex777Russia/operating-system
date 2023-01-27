package com.company;

public class PrintThread extends Thread {
    public static Object lock = new Object();
    private int max;
    private int divider1;
    private String message1;
    private int divider2;
    private String message2;

    protected static int current = 1;

    public PrintThread(int max, String message1, int divider1, String message2, int divider2) {
        this.max = max;
        this.message1 = message1;
        this.divider1 = divider1;
        this.message2 = message2;
        this.divider2 = divider2;
    }
    public void print1() {
        if (message1 != null && message2 != null) {
            System.out.println(message1 + message2);
        }
    }
    public void print2() {
        if (message1 != null) {
            System.out.println(message1);
        }
    }
    public void print3() {
        if (message2 != null) {
            System.out.println(message2);
        }
    }
    public void run() {
        while (true) {
            synchronized (lock) {
                if (current > max) {
                    return;
                }
                if (divider1 == 0 && divider2 == 0 ) {
                    System.out.println(current);
                    current++;
                } else if (current % (divider1 * divider2) == 0) {
                    print1();
                    current++;
                } else if (current % divider1 == 0) {
                    print2();
                    current++;
                } else if (current % divider2 == 0) {
                    print3();
                    current++;
                }

                try {
                    Thread.sleep(200);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}