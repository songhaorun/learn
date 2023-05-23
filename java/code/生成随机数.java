import java.util.Scanner;

import 生成随机数.Rand;

public class 生成随机数 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Runtime.getRuntime().addShutdownHook(new Thread() {
            @Override
            public void run() {
                in.close();
            }
        });
        System.out.println("输入最小值和最大值");
        int min = in.nextInt(), max = in.nextInt();
        while (true) {
            if (in.hasNextLine()) {
                in.nextLine();
                System.out.print(Rand.randomFrom(min, max));
            }
        }
    }
}
