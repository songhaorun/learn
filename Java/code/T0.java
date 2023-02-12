import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.file.Paths;
import java.util.Scanner;

import edge书签.Bookmarks;

public class T0 {
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
		t.print();
		in.close();
	}
}