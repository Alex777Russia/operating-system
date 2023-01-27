package com.company;

public class Main {

    public static void main(String[] args) {
        Thread[] threads = {
                new PrintThread(100, "  Привет", 3, "   Мир!", 5),
                new NumberThread(100, null, 0, null, 0)
        };
        for (var th: threads) {

            th.start();
        }
    }
}
