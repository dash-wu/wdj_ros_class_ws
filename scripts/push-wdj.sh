#!/usr/bin/env bash
# 将当前仓库推到 git@github.com:dash-wu/wdj_ros_class_ws.git
# 用法：./scripts/push-wdj.sh [远程名] [本地分支[:远程分支]]
# 默认：远程 backup，推送 d_ros_class_ws -> d_ros_class_ws（与实验 README 工作空间名一致）
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

REMOTE="${1:-backup}"
SPEC="${2:-d_ros_class_ws:d_ros_class_ws}"

if [[ "$SPEC" != *:* ]]; then
  SPEC="${SPEC}:${SPEC}"
fi

exec git push -u "$REMOTE" "$SPEC"
