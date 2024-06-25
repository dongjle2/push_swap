unique_numbers=()
while [[ ${#unique_numbers[@]} -lt 10 ]]; do
    random_number=$(( RANDOM % 100 + 1 ))
    if [[ ! " ${unique_numbers[@]} " =~ " $random_number " ]]; then
        unique_numbers+=( $random_number )
    fi
done

space_separated_numbers=$(printf "%s " "${unique_numbers[@]}")

# Print the space-separated numbers
echo $space_separated_numbers > 'numbers.txt'

# Construct the JSON array string
args_json="["
for ((i=0; i<${#unique_numbers[@]}; i++)); do
    args_json+="\"${unique_numbers[i]}\""
    if [[ $i -lt $(( ${#unique_numbers[@]} - 1 )) ]]; then
        args_json+=","
    fi
done
args_json+="]"

# Update the "args" field in the launch.json file
launch_json_file="./.vscode/launch.json"
tmp_file=$(mktemp)
jq --argjson args "$args_json" '.configurations[0].args = $args' "$launch_json_file" > "$launch_json_file.tmp" && mv "$launch_json_file.tmp" "$launch_json_file"
./a.out "${unique_numbers[@]}" > 'instructions.txt'
