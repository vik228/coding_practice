defmodule Rectangle do


  @symbol_map %{
    ">" => "$gt",
    "<" => "$lt",
    "and" => "$and",
    "or" => "$or"
  }

  def area_loop do
    receive do
      {:area, w, h} -> 
        IO.puts("Area = #{w*h}")
        area_loop()
      {:pmeter, w, h} ->
        IO.puts("Pmeter = #{w + h}")
        area_loop()
    end
  end

  def recurse_map(m) do
    Enum.each m, fn(key, value) ->
      cond do
        is_list(value) ->
          Enum.map value, fn(obj) ->
            recurse_map(obj)
          end
        is_map(value) ->
          recurse_map(value)
        true ->
          if Map.has_key?(@symbol_map, :key) do
            Map.put(filter, @symbol_map[:key], value)
            filter
          else
            Map.put(filter, key, value)
            filter
          end
      end
    end
  end

end
