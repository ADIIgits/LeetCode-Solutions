# 🧠 LeetCode Solutions

My LeetCode solutions, automatically synced to GitHub via a daily GitHub Actions workflow.

---

## 🔄 How it Works

A **GitHub Actions** workflow runs every day at midnight UTC and automatically fetches all **newly accepted** LeetCode submissions using your LeetCode session cookies — then commits and pushes them to this repo, organized by problem.

Solutions are organized in folders by problem name and include the solution file in the language you submitted.

---

## ⚙️ Setup (One-Time)

### 1. Get your LeetCode session cookies
1. Log in to [leetcode.com](https://leetcode.com)
2. Open DevTools (`F12`) → **Network** tab → Refresh the page
3. Click on any request to `leetcode.com` → look at **Request Headers → Cookie**
4. Copy the values for:
   - `LEETCODE_SESSION`
   - `csrftoken`

### 2. Add secrets to this GitHub repo
Go to: **Repo → Settings → Secrets and variables → Actions → New repository secret**

Add these two secrets:
| Secret Name | Value |
|---|---|
| `LEETCODE_SESSION` | Your `LEETCODE_SESSION` cookie value |
| `LEETCODE_CSRF_TOKEN` | Your `csrftoken` cookie value |

### 3. Enable workflow write permissions
Go to: **Repo → Settings → Actions → General → Workflow permissions**

Select **"Read and write permissions"** and save.

### 4. Run it!
Go to **Actions → Sync LeetCode Solutions → Run workflow** to trigger your first sync manually. After that it runs **automatically every day**!

---

## 📄 License

Personal project. Feel free to fork the setup for your own use!
