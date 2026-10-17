class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] words = sentence.split(" ");
        int n = words.length;
        for (int i = 0; i < n; i++) {
            String cur = words[i];
            String next = words[(i + 1) % n];
            if (cur.charAt(cur.length() - 1) != next.charAt(0)) {
                return false;
            }
        }
        return true;
    }
}