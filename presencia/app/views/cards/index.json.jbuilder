json.array!(@cards) do |card|
  json.extract! card, :id, :codigo, :usuario_id, :activa
  json.url card_url(card, format: :json)
end
