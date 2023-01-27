package com.company;

public class NumberThread extends PrintThread {
    public NumberThread(int max, String message1, int divider1, String message2, int divider2) {
        super(max, message1, divider1, message2, divider2);
    }
    public void print() {
        System.out.println(current);
    }
}
