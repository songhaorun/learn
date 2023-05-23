package edge书签;

import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

public class Bookmarks {
	private Scanner in;
	private PrintStream out;
	public Folder folder;

	// 构造函数
	public Bookmarks(String s) {
		this.folder = new Folder(s);
	}

	public Bookmarks(String s, InputStream in, OutputStream out) {
		this.folder = new Folder(s);
		this.in = new Scanner(in, "UTF-8");
		try {
			this.out = new PrintStream(out, true, "UTF-8");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public Bookmarks(String s, Scanner in, PrintStream out) {
		this.folder = new Folder(s);
		this.in = in;
		this.out = out;
	}

	public Bookmarks(Folder f) {
		this.folder = f;
	}

	public Bookmarks(Folder f, InputStream in, OutputStream out) {
		this.folder = f;
		this.in = new Scanner(in, "UTF-8");
		try {
			this.out = new PrintStream(out, true, "UTF-8");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public Bookmarks(Folder f, Scanner in, PrintStream out) {
		this.folder = f;
		this.in = in;
		this.out = out;
	}

	// 直接设定值
	public void setFolder(Folder f) {
		this.folder = f;
	}

	public void setName(String name) {
		this.folder.name = name;
	}

	public void setInput(InputStream in) {
		this.in = new Scanner(in, "UTF-8");
	}

	public void setInput(InputStream in, String encoding) {
		this.in = new Scanner(in, encoding);
	}

	public void setOutput(OutputStream out) {
		try {
			this.out = new PrintStream(out, true, "UTF-8");
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void setOutput(OutputStream out, String encoding) {
		try {
			this.out = new PrintStream(out, true, encoding);
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	// 输入
	public void getBookmarks() {
		this.folder.getFolder(in);
	}

	// 处理

	public Bookmarks findFolders(ArrayList<ArrayList<String>> names) {// 在文件夹中寻找多个路径为name[1]/name[2]/.../name[n]的文件夹(不包括整个文件夹)
		return new Bookmarks(this.folder.findFolders(names), in, out);
	}

	public Bookmarks findAllFoldersExact(ArrayList<ArrayList<String>> names) {// 在文件夹和子文件夹中寻找多个路径为.../name[1]/name[2]/.../names[n]的文件夹(不包括整个文件夹)
		return new Bookmarks(this.folder.findAllFoldersExact(names), in, out);
	}

	public Bookmarks findAllFolders(ArrayList<ArrayList<String>> names) {// 在文件夹和子文件夹中寻找多个路径为.../name[1]/.../name[2]/.../names[n]的文件夹(不包括整个文件夹)
		return new Bookmarks(this.folder.findAllFolders(names), in, out);
	}

	public void numbered() {
		this.folder.numbered(0);
	}

	// 输出
	public void print() {
		this.folder.print("", out);
	}

	public void printToHtml() {
		out.println("<dl>");
		this.folder.printToHtml("\t", out);
		out.println("</dl>");
	}
}