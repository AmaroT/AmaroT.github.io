
### Instructions for Adding to GitHub

1. **Push Project Artifacts**:
   - Ensure your Project Two dashboard code and README (Word document) are in your repository:
     ```bash
     cd /Users/amaroterrazas/documents/gh-repository/cs-340\ server/server\ dev/week8
     git add .
     git commit -m "Add Project Two dashboard code and README"
     git push origin main
     ```

2. **Add README.md**:
   - Create or update `README.md` in your repository:
     ```bash
     nano README.md
     ```
     - Copy and paste the Markdown content above.
     - Save (`Ctrl+O`, `Enter`, `Ctrl+X`).
   - Commit and push:
     ```bash
     git add README.md
     git commit -m "Add CS-340 journal reflection README"
     git push origin main
     ```
   - Alternatively, edit `README.md` directly in GitHub’s web interface:
     - Navigate to your repository.
     - Click “Create new file” or edit `README.md`.
     - Paste the content and commit.

3. **MongoDB Assignment**:
   - For your MongoDB tasks (importing `companies.json` and running queries/aggregations), ensure you’ve resolved the JSON format and authentication issues:
     ```bash
     mongoimport --host 127.0.0.1 --port 27017 --username admin --password password --authenticationDatabase admin --db companies --collection research --file /Users/amaroterrazas/documents/gh-repository/cs-340\ server/server\ dev/week8/companies.json
     ```
     - If the JSON error (`bad JSON array format`) persists, share the output of:
       ```bash
       head -n 10 /Users/amaroterrazas/documents/gh-repository/cs-340\ server/server\ dev/week8/companies.json
       ```
     - Include screenshots of the `mongoimport`, verification queries, and aggregation pipeline in your submission.

4. **Screenshots**:
   - For the MongoDB assignment, capture:
     - `mongoimport` command and output.
     - Verification queries (`db.research.find({"name": "AdventNet"})`, etc.).
     - Aggregation pipeline and results.
   - Store screenshots in your repository or submit them as required by your instructor.

### Notes
- The README is concise, professional, and addresses all prompt questions while linking to your MongoDB work for context.
- If you need help with Git commands, MongoDB import, or formatting, let me know!
- Share any errors or the `head` output for `companies.json` to resolve import issues.