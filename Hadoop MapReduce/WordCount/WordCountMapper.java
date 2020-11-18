import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
public class WordCountMapper
extends Mapper<LongWritable, Text, Text, IntWritable> {
        private static final int MISSING = 9999;

        @Override
                public void map(LongWritable key, Text value, Context context)
                throws IOException, InterruptedException {
                        String[] searchTerms = {"Chicago", "Dec", "Java", "hackathon"};
                        String line = value.toString();
                        for(int i = 0; i < searchTerms.length; i++){
                                if(line.toLowerCase().contains(searchTerms[i].toLowerCase())){
                                        context.write(new Text(searchTerms[i]), new IntWritable(1));
                                }
                                else{
                                        context.write(new Text(searchTerms[i]), new IntWritable(0));
                                }
                        }

                }
}
