
/* 从html文件中导入书签，搜索对应文件夹下的所有书签，以随机顺序输出
 * 
 * 输入格式：
 * 	输入文件路径
 * 	要搜索的文件夹个数
 * 		文件夹1（如搜索1文件夹中的2文件夹 输入“1 2”）
 * 		······
 */
import java.io.FileInputStream;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import edge书签.Bookmark;
import edge书签.Bookmarks;
import 生成随机数.Rand;

public class T2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Bookmarks t = new Bookmarks("收藏夹");
        try {
            t.setInput(new FileInputStream(Paths.get(in.nextLine()).toFile()));
        } catch (Exception e) {
            e.printStackTrace();
        }
        t.getBookmarks();
        int n = in.nextInt();
        in.nextLine();
        ArrayList<ArrayList<String>> names = new ArrayList<>();
        for (int i = 1; i <= n; ++i)
            names.add(new ArrayList<>(Arrays.asList(in.nextLine().split(" "))));
        ArrayList<Bookmark> b = t.folder.findAllFolders(names).getAllBookmark();
        for (int i : Rand.randomFromAll(0, b.size() - 1)) {
            System.out.print(b.get(i).name + "\n" + b.get(i).link);
            in.nextLine();
        }
        in.close();
    }
}
