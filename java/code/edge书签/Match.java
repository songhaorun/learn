/*
 * 正则表达式
 */
package edge书签;

import java.io.InputStream;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Match {
	public static void printGroup(Matcher m) {// 输出m中的每一个组
		for (int i = 0; i <= m.groupCount(); ++i)
			System.out.println(i + ":" + m.group(i));
	}

	public static void ifCatch() {
		Scanner in = new Scanner(System.in);
		String t1, t2;
		do {
			t1 = in.nextLine();
			t2 = in.nextLine();
			System.out.println(Pattern.matches(t1, t2));
		} while (!t1.equals("@"));
		in.close();
	}

	public static void match(String regax, InputStream in) {
		Scanner fin = new Scanner(in);
		Pattern r = Pattern.compile(regax);
		while (fin.hasNextLine()) {
			String s = fin.nextLine();
			Matcher m = r.matcher(s);
			if (m.find()) {
				printGroup(m);
				System.out.print("\n");
			}
		}
		fin.close();
	}
}