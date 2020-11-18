import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.LongWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;
public class CleanMapper
extends Mapper<LongWritable, Text, Text, Text> {
        private static final int MISSING = 9999;
        @Override
                public void map(LongWritable key, Text value, Context context)
                throws IOException, InterruptedException {
                         String line = value.toString();
                         String[] split = line.split(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)", -1);
                        if(split.length > 10){
                                context.write(new Text(split[2] + "," + split[3] + "," + split[4] + "," + split[5] + "," + split[6] + "," + split[7] + "," + split[8] + "," + split[9]), new Text(""));
                        }
               }                    
}
