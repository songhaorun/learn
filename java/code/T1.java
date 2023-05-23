
/* 从html文件中导入书签，搜索对应文件夹下的所有书签，放在名为result的文件夹中，输出为html文件
 * 
 * 输入格式：
 * 	输入文件路径
 * 	输出文件路径
 * 	要搜索的文件夹个数
 * 		文件夹1（如搜索1文件夹中的2文件夹 输入“1 2”）
 * 		······
 */
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

import edge书签.Bookmarks;

public class T1 {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		Bookmarks t = null;
		try {
			t = new Bookmarks("收藏夹", new FileInputStream(Paths.get(in.nextLine()).toFile()),
					new FileOutputStream(Paths.get(in.nextLine()).toFile()));
		} catch (Exception e) {
			e.printStackTrace();
		}
		t.getBookmarks();
		int n = in.nextInt();
		in.nextLine();
		ArrayList<ArrayList<String>> names = new ArrayList<>();
		for (int i = 1; i <= n; ++i)
			names.add(new ArrayList<>(Arrays.asList(in.nextLine().split(" "))));
		Bookmarks b = t.findAllFolders(names);
		b.numbered();
		b.printToHtml();
		in.close();
	}
}
