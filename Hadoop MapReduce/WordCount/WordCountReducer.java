import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;
public class WordCountReducer
extends Reducer<Text, IntWritable, Text, IntWritable> {

        @Override
                public void reduce(Text key, Iterable<IntWritable> values, Context context)
                throws IOException, InterruptedException {
                        /*for (Text word : key) {
                                int sum = 0;
                                for(IntWritable value : word.get()){
                                        sum += value;
                                }
                                context.write(key, newIntWritable(sum));
                        }*/
                        int sum = 0;
                        for(IntWritable value : values) {
                                sum = sum + value.get();
                        }
                        context.write(key, new IntWritable(sum));

                }
}
