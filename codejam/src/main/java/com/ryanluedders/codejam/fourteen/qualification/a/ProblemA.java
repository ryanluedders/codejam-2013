package com.ryanluedders.codejam.fourteen.qualification.a;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.apache.commons.io.FileUtils;

import com.thoughtworks.xstream.XStream;

/**
 * Hello world!
 *
 */
public class ProblemA
{
	private static final String BAD_MAGICIAN =
			"Bad magician!";
	private static final String VOLUNTEER_CHEATED =
			"Volunteer cheated!";
	private static final String RESULT_FORMAT =
			"Case #%s: %s";

	private static final XStream X = new XStream();

	private static class Problem {
		int numberCases;
		List<Case> cases = new ArrayList<Case>();
	};

	private static class Case {
		List<Draw> draws = new ArrayList<Draw>();
	};

	private static class Draw {
		int result;
		String[] rows = new String[4];
	};

    public static void main( String[] args ) throws IOException
    {
		File inputFile = new File("./src/main/resources/a.in");
		List<String> data = FileUtils.readLines(inputFile,"UTF-8");

		File outputFile = new File("./src/main/resources/a.out");
		outputFile.delete();

		Problem problem = new Problem();
		problem.numberCases = Integer.valueOf(data.get(0));

		for(int i=0; i<problem.numberCases; i++) {
			problem.cases.add(readCase(data, (i*10)+1));
		}

		int caseNumber = 1;
		for(Case c : problem.cases) {
			Map<Integer,Integer> count = new HashMap<Integer,Integer>();
			for(Draw d : c.draws) {
				List<String> cardsShown = Arrays.asList(
						d.rows[d.result-1].split(" "));
				for(String card : cardsShown) {
					Integer cardNo = Integer.valueOf(card);

					if (count.get(cardNo) == null) {
						count.put(cardNo, 0);
					}

					Integer startCount = count.get(cardNo);
					count.put(cardNo, startCount+1);
				}
			}

			List<Integer> results = new ArrayList<Integer>();
			for(int i=1; i<=16; i++) {
				if (count.get(i) != null && count.get(i) == 2) {
					results.add(i);
				}
			}

			String result;
			if(results.size() == 0) {
				result = VOLUNTEER_CHEATED;
			}
			else if(results.size() > 1) {
				result = BAD_MAGICIAN;
			}
			else {
				result = Integer.toString(results.get(0));
			}

			String resultText = String.format(
					RESULT_FORMAT,
					Integer.toString(caseNumber),
					result
					);
			String fileText = resultText;

			if (caseNumber > 1) {
				fileText = "\n" + fileText;
			}
			FileUtils.writeStringToFile(outputFile, fileText, true);
			System.out.println(resultText);

			caseNumber += 1;
		}
    }

    private static Case readCase(List<String> lines, int startIdx) {
    	Draw draw1 = new Draw();
    	draw1.result = Integer.valueOf(lines.get(startIdx++));
    	for(int i=0; i<4; i++) {
    		draw1.rows[i] = lines.get(startIdx++);
    	}

    	Draw draw2 = new Draw();
    	draw2.result = Integer.valueOf(lines.get(startIdx++));
    	for(int i=0; i<4; i++) {
    		draw2.rows[i] = lines.get(startIdx++);
    	}

    	Case cardCase = new Case();
    	cardCase.draws.add(draw1);
    	cardCase.draws.add(draw2);
    	return cardCase;
    }
}
