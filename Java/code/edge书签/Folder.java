package edge书签;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Folder {
    public String name;
    public ArrayList<Folder> floders;
    public ArrayList<Bookmark> bookmarks;

    // 构造函数
    public Folder(String name) {
        this.name = name;
        this.floders = new ArrayList<>();
        this.bookmarks = new ArrayList<>();
    }

    // 输入
    public void getFolder(Scanner in) {
        Pattern r = Pattern.compile("(?i).*<(.*?)( href=\"(.*?)\")?.*>(.*)</\\1>");
        while (true) {
            String s = in.nextLine();
            if (s.toLowerCase().contains("</dl>"))
                return;
            Matcher m = r.matcher(s);
            if (m.lookingAt())
                switch (m.group(1)) {
                    case "H3":
                        Folder f = new Folder(m.group(4));
                        f.getFolder(in);
                        this.floders.add(f);
                        break;
                    case "A":
                    case "a":
                        this.bookmarks.add(new Bookmark(m.group(4), m.group(3)));
                        break;
                }
        }
    }

    // 处理
    public ArrayList<Bookmark> getAllBookmark() {
        ArrayList<Bookmark> ans = new ArrayList<>();
        for (Folder f : this.floders)
            ans.addAll(f.getAllBookmark());
        ans.addAll(this.bookmarks);
        return ans;
    }

    public int numbered(int n) {
        for (Folder f : this.floders)
            n = f.numbered(n);
        for (Bookmark b : this.bookmarks)
            b.name = ++n + ":\t" + b.name;
        return n;
    }

    public ArrayList<Folder> findFolder(String name) {// 在文件夹中寻找名字为name的文件夹(不包括整个文件夹)
        ArrayList<Folder> ans = new ArrayList<>();
        for (Folder f : this.floders)
            if (f.name.equals(name))
                ans.add(f);
        return ans;
    }

    public ArrayList<Folder> findAllFolder(String name) {// 在文件夹和子文件夹中寻找名字为name的文件夹(不包括整个文件夹)
        ArrayList<Folder> ans = new ArrayList<>();
        for (Folder f : this.floders) {
            if (f.name.equals(name))
                ans.add(f);
            ans.addAll(f.findAllFolder(name));
        }
        return ans;
    }

    public ArrayList<Folder> findFolder(ArrayList<String> name) {// 在文件夹中寻找路径为name[1]/name[2]/.../name[n]的文件夹(不包括整个文件夹)
        if (name.size() == 1)
            return this.findFolder(name.get(0));
        ArrayList<Folder> ans = new ArrayList<>();
        for (Folder f : this.floders)
            if (f.name.equals(name.get(0))) {
                ArrayList<Folder> t = f.findFolder(new ArrayList<>(name.subList(1, name.size())));
                if (!t.isEmpty()) {
                    Folder tf = new Folder(f.name);
                    tf.floders.addAll(t);
                    ans.add(tf);
                }
            }
        return ans;
    }

    public Folder findFolders(ArrayList<ArrayList<String>> names) {
        Folder ans = new Folder("result");
        for (ArrayList<String> name : names)
            ans.floders.addAll(this.findFolder(name));
        return ans;
    }

    public ArrayList<Folder> findAllFolderExact(ArrayList<String> name) {// 在文件夹和子文件夹中寻找路径为.../name[1]/name[2]/.../names[n]的文件夹(不包括整个文件夹)
        if (name.size() == 1)
            return this.findFolder(name.get(0));
        ArrayList<Folder> ans = new ArrayList<>();
        for (Folder f : this.floders) {
            if (f.name.equals(name.get(0))) {
                ArrayList<Folder> t = f.findFolder(new ArrayList<>(name.subList(1, name.size())));
                if (!t.isEmpty()) {
                    Folder tf = new Folder(f.name);
                    tf.floders.addAll(t);
                    ans.add(tf);
                }
            }
            ans.addAll(f.findAllFolder(name));
        }
        return ans;
    }

    public Folder findAllFoldersExact(ArrayList<ArrayList<String>> names) {
        Folder ans = new Folder("result");
        for (ArrayList<String> name : names)
            ans.floders.addAll(this.findAllFolderExact(name));
        return ans;
    }

    public ArrayList<Folder> findAllFolder(ArrayList<String> name) {// 在文件夹和子文件夹中寻找路径为.../name[1]/.../name[2]/.../names[n]的文件夹(不包括整个文件夹)
        if (name.size() == 1)
            return this.findAllFolder(name.get(0));
        ArrayList<Folder> ans = new ArrayList<>();
        for (Folder f : this.floders) {
            if (f.name.equals(name.get(0))) {
                ArrayList<Folder> t = f.findAllFolder(new ArrayList<>(name.subList(1, name.size())));
                if (!t.isEmpty()) {
                    Folder tf = new Folder(f.name);
                    tf.floders.addAll(t);
                    ans.add(tf);
                }
            }
            ans.addAll(f.findAllFolder(name));
        }
        return ans;
    }

    public Folder findAllFolders(ArrayList<ArrayList<String>> names) {
        Folder ans = new Folder("result");
        for (ArrayList<String> name : names)
            ans.floders.addAll(this.findAllFolder(name));
        return ans;
    }

    // 输出
    public void print(String s, PrintStream out) {
        out.print(s + this.name + "\n");
        for (Folder f : this.floders)
            f.print(s + "\t", out);
        for (Bookmark b : this.bookmarks)
            out.print(s + "\t" + b.name + ":" + b.link + "\n");
    }

    public void printToHtml(String s, PrintStream out) {
        out.printf("%s<H3>%s</H3>\n", s, this.name);
        out.println(s + "<dl>");
        for (Folder f : this.floders)
            f.printToHtml(s + "\t", out);
        for (Bookmark b : this.bookmarks)
            out.printf("%s\t<a href=\"%s\">%s</a>\n", s, b.link, b.name);
        out.println(s + "</dl>");
    }
}