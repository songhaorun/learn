import java.util.ArrayList;
import java.util.Scanner;

import 生成随机数.Rand;

public class 决定 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Runtime.getRuntime().addShutdownHook(new Thread() {
            @Override
            public void run() {
                in.close();
            }
        });
        System.out.println("请输入选项个数");
        int n = in.nextInt();
        System.out.println("请输入" + n + "个选项");
        ArrayList<String> xuanxiang = new ArrayList<>();
        for (int i = 1; i <= n; ++i) {
            String s;
            s = in.next();
            xuanxiang.add(s);
        }
        while (true) {
            if (in.hasNextLine()) {
                in.nextLine();
                System.out.println(xuanxiang.get(Rand.randomFrom(0, n - 1)));
            }
        }
    }
}
