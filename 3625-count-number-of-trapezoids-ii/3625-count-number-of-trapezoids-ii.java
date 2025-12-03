import java.util.HashMap;

public class Solution {

    // Step 0 - GCD
    public int gcd(int a, int b) {
        a = Math.abs(a);
        b = Math.abs(b);
        while (b != 0) {
            int tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    // Step 1 - Normalize fraction for slope/intercept
    public String hash(int a, int b) {
        if (a == 0 && b == 0) return "0/0";
        int g = gcd(a, b);
        if (g == 0) return "0/0";
        a /= g;
        b /= g;
        // keep denominator positive
        if (b < 0) {
            a = -a;
            b = -b;
        }
        return a + "/" + b;
    }

    public int countTrapezoids(int[][] points) {
        int n = points.length;
        if (n < 4) return 0;

        long trapeziums_parallelograms = 0L;

        // Step 2 - Hash maps for parallel lines & collinear lines
        HashMap<String, Integer> parallel_lines = new HashMap<>();
        HashMap<String, Integer> collinear_lines = new HashMap<>();

        // Step 3 - Count all trapeziums + parallelograms
        for (int i = 0; i < n; i++) {
            int[] p2 = points[i];
            for (int j = 0; j < i; j++) {
                int[] p1 = points[j];

                // slope
                String slope = (p1[0] != p2[0])
                        ? hash(p2[1] - p1[1], p2[0] - p1[0])
                        : "infinity";

                // intercept (line constant)
                String intercept = (p1[0] != p2[0])
                        ? hash(p1[1] * (p2[0] - p1[0]) - (p2[1] - p1[1]) * p1[0],
                               p2[0] - p1[0])
                        : Integer.toString(p1[0]);

                String slope_key = slope;
                String full_line_key = slope + "," + intercept;

                int seen_parallel = parallel_lines.getOrDefault(slope_key, 0);
                int seen_collinear = collinear_lines.getOrDefault(full_line_key, 0);

                // Add trapeziums using previous parallel lines minus same-line duplicates
                trapeziums_parallelograms += (seen_parallel - seen_collinear);

                // Update
                parallel_lines.put(slope_key, seen_parallel + 1);
                collinear_lines.put(full_line_key, seen_collinear + 1);
            }
        }

        // Step 4 - Parallelogram detection using slope+distance
        long parallelograms = 0L;

        HashMap<String, Integer> parallel_lines_dist = new HashMap<>();
        HashMap<String, Integer> collinear_lines_dist = new HashMap<>();

        // Step 5 - Count parallelograms only
        for (int i = 0; i < n; i++) {
            int[] p2 = points[i];
            for (int j = 0; j < i; j++) {
                int[] p1 = points[j];

                String slope = (p1[0] != p2[0])
                        ? hash(p2[1] - p1[1], p2[0] - p1[0])
                        : "infinity";

                String intercept = (p1[0] != p2[0])
                        ? hash(p1[1] * (p2[0] - p1[0]) - (p2[1] - p1[1]) * p1[0],
                               p2[0] - p1[0])
                        : Integer.toString(p1[0]);

                int dx = p1[0] - p2[0];
                int dy = p1[1] - p2[1];
                int dist = dx * dx + dy * dy;

                String slope_dist_key = slope + "," + dist;
                String full_line_dist_key = slope + "," + intercept + "," + dist;

                int seen_parallel_dist = parallel_lines_dist.getOrDefault(slope_dist_key, 0);
                int seen_collinear_dist = collinear_lines_dist.getOrDefault(full_line_dist_key, 0);

                parallelograms += (seen_parallel_dist - seen_collinear_dist);

                parallel_lines_dist.put(slope_dist_key, seen_parallel_dist + 1);
                collinear_lines_dist.put(full_line_dist_key, seen_collinear_dist + 1);
            }
        }

        // Step 6 - Subtract parallelograms (each counted twice)
        long result = trapeziums_parallelograms - parallelograms;
        // result should fit into int per problem constraints, but cast safely
        return (int) result;
    }

    // optional main for quick manual testing
    public static void main(String[] args) {
        Solution s = new Solution();
        int[][] pts = { {-3,2},{3,0},{2,3},{3,2},{2,-3} };
        System.out.println(s.countTrapezoids(pts)); // expect 2
    }
}
