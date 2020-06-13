package personal.nicole.cu.cs227;

import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class HW1 {
    static class WordRecord {
        WordRecord(String w, int c) {
            this.word = w;
            this.count = c;
        }

        String word;
        int count;

        @Override
        public String toString() {
            return "WordRecord{" +
                    "word='" + word + '\'' +
                    ", count=" + count +
                    '}';
        }
    }

    private static String[] getIgnoreWordsArray(File ignoreWordsFile) {
        String[] ignoreArray = new String[10];
        try {
            FileReader fr = new FileReader(ignoreWordsFile);
            BufferedReader br = new BufferedReader(fr);
            int i = 0;
            while (br.ready()) {
                String word = br.readLine();
                if (i == ignoreArray.length) {
                    ignoreArray = Utils.doubleArray(String.class, ignoreArray);
                }
                ignoreArray[i] = word.trim();
                i++;
            }
            br.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return ignoreArray;
    }

    private static Map<String, WordRecord> processBook(URI uri) {
        HashMap<String, WordRecord> wordItems = new HashMap<>();
        try {
            InputStream isr = uri.toURL().openConnection().getInputStream();
            BufferedReader br = new BufferedReader(new InputStreamReader(isr));
            return processBufferedReader(br);
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return wordItems;
    }

    private static Map<String, WordRecord> processBook(File file) {
        HashMap<String, WordRecord> wordItems = new HashMap<>();
        try {
            BufferedReader br = new BufferedReader(new FileReader(file));
            return processBufferedReader(br);
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return wordItems;
    }

    private static Map<String, WordRecord> processBufferedReader(BufferedReader br) {
        HashMap<String, WordRecord> wordItems = new HashMap<>();
        try {
            while (br.ready()) {
                StringTokenizer st = new StringTokenizer(br.readLine(), " ");
                while (st.hasMoreTokens()) {
                    String currentWord = st.nextToken();
                    if (!wordItems.containsKey(currentWord)) {
                        wordItems.put(currentWord, new WordRecord(currentWord, 1));
                    } else {
                        wordItems.get(currentWord).count++;
                    }
                }
            }
            br.close();
        } catch (Throwable e) {
            e.printStackTrace();
        }
        return wordItems;
    }

    private static int findDistinctWord(String word, WordRecord[] wordsRecords) {
        int i = 0;
        if (word == null || wordsRecords == null || wordsRecords.length == 0) {
            return -1;
        }

        for (WordRecord wr : wordsRecords) {
            if (wr != null && wr.word.equals(word)) {
                return i;
            }
            i++;
        }
        return -1;
    }

    public static void main(String[] args) throws URISyntaxException {
        int nTopWords = Integer.parseInt(args[0]);
        File bookFile = new File(args[1]);
        File ignoreWordsFile = new File(args[2]);
        String[] ignoreWordsArray = getIgnoreWordsArray(ignoreWordsFile);
        Map<String, WordRecord> wordRecords = processBook(bookFile); //new URI("https://www.diariobitcoin.com/simbolo/BTC"));
        Utils.printMap(wordRecords);
    }
}