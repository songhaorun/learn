package 生成随机数;

import java.util.ArrayList;
import java.util.Arrays;

public class Rand {
    public static int randomFrom(int min, int max) {// 返回min到max中随机一个数（包括min，max）
        return min + (int) (Math.random() * (max - min + 1));
    }

    public static int randomFrom(Range... ranges) {// 返回ranges中随机一个数
        ArrayList<Integer> all = new ArrayList<>();
        for (Range i : ranges)
            for (int j = i.min; j <= i.max; ++j)
                all.add(j);
        return all.get(randomFrom(0, all.size() - 1));
    }

    public static ArrayList<Integer> randomFromAll(int min, int max) {// 以随机顺序返回min到max中所有数（包括min，max）
        ArrayList<Integer> ans = new ArrayList<>();
        if (min <= max) {
            boolean[] b = new boolean[max - min + 1];
            Arrays.fill(b, false);
            for (int i = min; i <= max; ++i) {
                int t;
                do {
                    t = randomFrom(min, max);
                } while (b[t - min]);
                ans.add(t);
                b[t - min] = true;
            }
        }
        return ans;
    }

    public static ArrayList<Integer> randomFromAll(Range... ranges) {// 以随机顺序返回ranges中所有数
        ArrayList<Integer> ans = new ArrayList<>(), all = new ArrayList<>();
        for (Range i : ranges)
            for (int j = i.min; j <= i.max; ++j)
                all.add(j);
        for (int i : randomFromAll(0, all.size() - 1))
            ans.add(all.get(i));
        return ans;
    }
}
