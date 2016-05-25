json.array!(@logs) do |log|
  json.extract! log, :id, :tiempo_lectora, :tiempo_registro, :equipo_id, :card_id, :usuario_id
  json.url log_url(log, format: :json)
end
